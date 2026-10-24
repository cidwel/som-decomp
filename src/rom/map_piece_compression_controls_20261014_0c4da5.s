.setcpu "65816"
.segment "CODE"
.org $4DA5
map_control_0c4da5:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
