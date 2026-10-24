.setcpu "65816"
.segment "CODE"
.org $3943
map_control_0c3943:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
