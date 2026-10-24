.setcpu "65816"
.segment "CODE"
.org $C3EB
map_control_0dc3eb:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
