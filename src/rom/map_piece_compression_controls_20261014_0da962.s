.setcpu "65816"
.segment "CODE"
.org $A962
map_control_0da962:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
