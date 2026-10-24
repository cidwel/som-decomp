.setcpu "65816"
.segment "CODE"
.org $D591
map_control_0dd591:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $D3 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $57 ; row-distance/count
