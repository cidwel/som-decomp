.setcpu "65816"
.segment "CODE"
.org $AEF1
map_control_0eaef1:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
