.setcpu "65816"
.segment "CODE"
.org $CB80
map_control_0dcb80:
    .byte $E1 ; previous-row copy count
