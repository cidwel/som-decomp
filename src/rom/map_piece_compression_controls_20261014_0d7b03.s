.setcpu "65816"
.segment "CODE"
.org $7B03
map_control_0d7b03:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
