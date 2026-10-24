.setcpu "65816"
.segment "CODE"
.org $F515
map_control_0ff515:
    .byte $E3 ; previous-row copy count
