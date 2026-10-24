.setcpu "65816"
.segment "CODE"
.org $56E9
map_control_0d56e9:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $56 ; row-distance/count
