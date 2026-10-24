.setcpu "65816"
.segment "CODE"
.org $0F24
map_control_0f0f24:
    .byte $E1 ; previous-row copy count
