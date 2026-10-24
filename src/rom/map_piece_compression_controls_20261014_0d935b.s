.setcpu "65816"
.segment "CODE"
.org $935B
map_control_0d935b:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
