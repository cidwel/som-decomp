; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $59E0
control_parameters_59e0:
    .byte $00, $00, $00 ; signed component offsets, kernel0
    .byte $00, $00, $01 ; signed component offsets, kernel1
    .byte $00, $01, $01 ; signed component offsets, kernel2
    .byte $01, $01, $01 ; signed component offsets, kernel3
    .byte $00, $00, $02 ; signed component offsets, kernel4
    .byte $00, $01, $02 ; signed component offsets, kernel5
    .byte $02, $01, $00 ; signed component offsets, kernel6
    .byte $01, $01, $02 ; signed component offsets, kernel7
