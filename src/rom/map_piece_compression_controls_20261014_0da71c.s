.setcpu "65816"
.segment "CODE"
.org $A71C
map_control_0da71c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
