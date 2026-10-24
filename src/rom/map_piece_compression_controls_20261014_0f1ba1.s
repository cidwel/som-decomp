.setcpu "65816"
.segment "CODE"
.org $1BA1
map_control_0f1ba1:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
