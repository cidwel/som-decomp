.setcpu "65816"
.segment "CODE"
.org $DC7B
map_control_0edc7b:
    .byte $E5 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
