.setcpu "65816"
.segment "CODE"
.org $FBAF
map_control_0efbaf:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
