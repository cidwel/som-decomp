.setcpu "65816"
.segment "CODE"
.org $5FB9
map_control_0f5fb9:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
