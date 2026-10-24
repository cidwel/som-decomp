.setcpu "65816"
.segment "CODE"
.org $8E80
map_control_0c8e80:
    .byte $F0 ; progressive-copy escape
    .byte $08 ; direction/count
    .byte $E1 ; previous-row copy count
