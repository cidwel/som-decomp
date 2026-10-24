.setcpu "65816"
.segment "CODE"
.org $CC8B
map_control_0fcc8b:
    .byte $D5 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
