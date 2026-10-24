.setcpu "65816"
.segment "CODE"
.org $1C14
map_control_0f1c14:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
