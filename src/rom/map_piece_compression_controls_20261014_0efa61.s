.setcpu "65816"
.segment "CODE"
.org $FA61
map_control_0efa61:
    .byte $E8 ; backreference distance high bits
    .byte $28 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
