.setcpu "65816"
.segment "CODE"
.org $3B09
map_control_0f3b09:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
