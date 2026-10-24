.setcpu "65816"
.segment "CODE"
.org $B731
map_control_0eb731:
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
