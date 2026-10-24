.setcpu "65816"
.segment "CODE"
.org $161A
map_control_0d161a:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B8 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $C0 ; row-distance/count
