.setcpu "65816"
.segment "CODE"
.org $6B09
map_control_0c6b09:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
