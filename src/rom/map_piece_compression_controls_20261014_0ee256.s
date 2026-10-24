.setcpu "65816"
.segment "CODE"
.org $E256
map_control_0ee256:
    .byte $E1 ; previous-row copy count
