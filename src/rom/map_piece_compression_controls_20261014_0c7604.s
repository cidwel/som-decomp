.setcpu "65816"
.segment "CODE"
.org $7604
map_control_0c7604:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
