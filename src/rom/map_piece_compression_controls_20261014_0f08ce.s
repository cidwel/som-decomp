.setcpu "65816"
.segment "CODE"
.org $08CE
map_control_0f08ce:
    .byte $E1 ; previous-row copy count
