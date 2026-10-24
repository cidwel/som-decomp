.setcpu "65816"
.segment "CODE"
.org $6173
map_control_0d6173:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
