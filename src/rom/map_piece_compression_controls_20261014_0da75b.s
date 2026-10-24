.setcpu "65816"
.segment "CODE"
.org $A75B
map_control_0da75b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
