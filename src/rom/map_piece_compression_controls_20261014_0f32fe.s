.setcpu "65816"
.segment "CODE"
.org $32FE
map_control_0f32fe:
    .byte $E4 ; previous-row copy count
