.setcpu "65816"
.segment "CODE"
.org $872A
map_control_0d872a:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
