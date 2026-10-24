.setcpu "65816"
.segment "CODE"
.org $2B68
map_control_0f2b68:
    .byte $E8 ; backreference distance high bits
    .byte $28 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
