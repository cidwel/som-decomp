.setcpu "65816"
.segment "CODE"
.org $6D24
map_control_0f6d24:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
