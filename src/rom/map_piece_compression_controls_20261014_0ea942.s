.setcpu "65816"
.segment "CODE"
.org $A942
map_control_0ea942:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
