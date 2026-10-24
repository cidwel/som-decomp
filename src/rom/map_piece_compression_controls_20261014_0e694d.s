.setcpu "65816"
.segment "CODE"
.org $694D
map_control_0e694d:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
