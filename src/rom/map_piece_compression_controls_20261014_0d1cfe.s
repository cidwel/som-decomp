.setcpu "65816"
.segment "CODE"
.org $1CFE
map_control_0d1cfe:
    .byte $CC ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
