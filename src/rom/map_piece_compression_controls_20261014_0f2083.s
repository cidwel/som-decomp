.setcpu "65816"
.segment "CODE"
.org $2083
map_control_0f2083:
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E7 ; previous-row copy count
