.setcpu "65816"
.segment "CODE"
.org $809A
map_control_0d809a:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
