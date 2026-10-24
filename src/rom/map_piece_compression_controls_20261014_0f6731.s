.setcpu "65816"
.segment "CODE"
.org $6731
map_control_0f6731:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $49 ; distance low bit/count
