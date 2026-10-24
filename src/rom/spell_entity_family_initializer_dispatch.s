.setcpu "65816"
.segment "CODE"
.org $3B2E
; Seven native initializer families; modes1 and5 share twin callbacks.
.word $2BE8, $2C06, $2BF7, $2800, $2EDD, $2C06, $4801
