.setcpu "65816"
.segment "CODE"
.org $BA3C
map_control_0fba3c:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
