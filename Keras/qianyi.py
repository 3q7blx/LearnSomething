import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers

from keras.preprocessing.image import ImageDataGenerator


base_model = tf.keras.applications.mobilenet_v2.MobileNetV2(include_top=False,weights='imagenet',input_shape=(224,224,3)) # Do not include the ImageNet classifier at the top.
base_model.trainable = False

inputs = keras.Input(shape=(224, 224, 3))
# We make sure that the base_model is running in inference mode here,
# by passing `training=False`. This is important for fine-tuning, as you will
# learn in a few paragraphs.
x = base_model(inputs, training=False)
# Convert features of shape `base_model.output_shape[1:]` to vectors
x = keras.layers.GlobalAveragePooling2D()(x)
# A Dense classifier with a single unit (binary classification)
outputs = keras.layers.Dense(2,activation='softmax')(x)
model = keras.Model(inputs, outputs)

model.summary()
keras.utils.plot_model(model,'my_firist.png')

model.compile(optimizer=keras.optimizers.RMSprop(),
              loss=keras.losses.SparseCategoricalCrossentropy(),
              metrics=[keras.metrics.SparseCategoricalAccuracy(name='train_accuracy')])

img_width = 224
img_height = 224
train_data_dir = 'data/train'
valid_data_dir = 'data/test'

datagen = ImageDataGenerator(rescale = 1./255)

train_generator = datagen.flow_from_directory(directory=train_data_dir,target_size=(img_width,img_height),classes=['dog','cat'],class_mode='binary',batch_size=16)

validation_generator = datagen.flow_from_directory(directory=valid_data_dir,target_size=(img_width,img_height),classes=['dog','cat'],class_mode='binary', batch_size=32)

training = model.fit_generator(generator=train_generator, steps_per_epoch=25000 // 16,epochs=1,validation_data=validation_generator,validation_steps=12500//32)


# model.fit(new_dataset, epochs=20, callbacks=..., validation_data=...)

# test_scores = model.evaluate(x_test, y_test, verbose=2)
model.save('model.h5')

