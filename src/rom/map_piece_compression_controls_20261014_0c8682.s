.setcpu "65816"
.segment "CODE"
.org $8682
map_control_0c8682:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count
