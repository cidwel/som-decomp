.setcpu "65816"
.segment "CODE"
.org $9CFD
map_control_0d9cfd:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
