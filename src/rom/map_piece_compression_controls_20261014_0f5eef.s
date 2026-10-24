.setcpu "65816"
.segment "CODE"
.org $5EEF
map_control_0f5eef:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
