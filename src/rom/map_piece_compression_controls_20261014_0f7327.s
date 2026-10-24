.setcpu "65816"
.segment "CODE"
.org $7327
map_control_0f7327:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E1 ; previous-row copy count
