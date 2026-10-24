.setcpu "65816"
.segment "CODE"
.org $A931
map_control_0fa931:
    .byte $D5 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
