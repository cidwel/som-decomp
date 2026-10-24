.setcpu "65816"
.segment "CODE"
.org $FB80
map_control_0dfb80:
    .byte $E5 ; previous-row copy count
