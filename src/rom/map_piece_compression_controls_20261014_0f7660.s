.setcpu "65816"
.segment "CODE"
.org $7660
map_control_0f7660:
    .byte $ED ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
