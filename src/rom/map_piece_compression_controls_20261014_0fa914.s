.setcpu "65816"
.segment "CODE"
.org $A914
map_control_0fa914:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
