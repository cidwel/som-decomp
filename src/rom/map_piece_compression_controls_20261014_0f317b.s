.setcpu "65816"
.segment "CODE"
.org $317B
map_control_0f317b:
    .byte $F2 ; progressive-copy count
    .byte $E3 ; previous-row copy count
