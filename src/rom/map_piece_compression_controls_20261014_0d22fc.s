.setcpu "65816"
.segment "CODE"
.org $22FC
map_control_0d22fc:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
