.setcpu "65816"
.segment "CODE"
.org $6869
map_control_0f6869:
    .byte $E4 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
