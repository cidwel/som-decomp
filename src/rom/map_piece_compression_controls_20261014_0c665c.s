.setcpu "65816"
.segment "CODE"
.org $665C
map_control_0c665c:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
