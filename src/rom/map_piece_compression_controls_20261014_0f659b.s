.setcpu "65816"
.segment "CODE"
.org $659B
map_control_0f659b:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
