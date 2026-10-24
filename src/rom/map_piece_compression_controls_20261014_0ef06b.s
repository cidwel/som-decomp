.setcpu "65816"
.segment "CODE"
.org $F06B
map_control_0ef06b:
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
